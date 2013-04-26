#AVRDUDE        = avrdude -P /dev/ttyS0 -c avrsp -p m168
#ARCH_PREFIX        = /usr/local/CrossPack-AVR-20131216/bin/avr-
#ARCH_PREFIX        = /opt/local/bin/avr-
ARCH_PREFIX = avr-

PRG            = firmware
#IMU_OBJS       = mpu6050_basic.o quaternionFilter.o
IMU_OBJS = 
USB_OBJS       = usb_descriptors.o usb_events.o
FONT_OBJS      = Font_digits6x13.o Font_digits23c.o Font_david6.o
OBJ            = main.o ra6963.o ra6963_gfx.o gfxfont.o gfx.o $(FONT_OBJS)  pcf8583-rtc.o vss.o kbd.o image.o console.o menu.o nvram.o gui.o eeprom.o screensaver.o $(USB_OBJS)  oddebug.o twimaster.o twi.o  $(IMU_OBJS)
#HOST_OBJ       = main.ho ../emulation/lc7981emu.so lc7981.ho gfxfont.ho gfx.ho Font_digits15c.ho Font_digits23c.ho Font_david6.ho rtctimeremu.ho vssemu.ho anim.ho screensaver.ho kbdemu.ho console.ho menu.ho nvemu.ho gui.ho image.ho
HOST_OBJ       = htool.ho
DEVICE         = atmega32u4
OPTIMIZE       = -Os
BOARD          = PROMICRO
AVRDUDE        = sudo avrdude -c TUMPA-A -p $(DEVICE) -v -B 1
F_CPU	       = 16000000
F_OSC          = $(F_CPU)
DEFS           = -I../Library -DBOARD=BOARD_$(BOARD) -DDEBUG_LEVEL=1
LIBS           =

LUFA_PATH = /Users/mr_w/Workspace/avr/lufa-build

LUFA_CFLAGS = -I$(LUFA_PATH) -DARCH=ARCH_AVR8 -DBOARD=BOARD_$(BOARD) -DF_USB=$(F_CPU)UL -DUSE_LUFA_CONFIG_HEADER -I$(LUFA_PATH)/Config/
LUFA_LIBS = -L$(LUFA_PATH) -llufa-$(BOARD)-$(DEVICE)

# You should not have to change anything below here.
HOST_CC        = gcc
HOST_CXX       = g++
HOST_LD        = $(HOST_CXX)
HOST_CFLAGS    = -g -Wall -Wno-parentheses $(DEFS) -DF_CPU=$(F_CPU) -DF_OSC=$(F_OSC) -I../drivers -I../emulation
HOST_CXXFLAGS  := $(HOST_CFLAGS) $(shell pkg-config libusb-1.0 --cflags)
HOST_LIBS      := $(shell pkg-config libusb-1.0 --libs)

CC             = $(ARCH_PREFIX)gcc
ASFLAGS        = -Wa,-adhlns=$(<:.S=.lst),-gstabs 
ALL_ASFLAGS    = -mmcu=$(DEVICE) -I. -x assembler-with-cpp $(ASFLAGS)
CFLAGS        = -g -Wall -Wno-parentheses $(OPTIMIZE) -mmcu=$(DEVICE) $(DEFS) -DF_CPU=$(F_CPU) -DF_OSC=$(F_OSC) -std=c99 \
		$(LUFA_CFLAGS) \
	        -std=c99 -ffunction-sections -fdata-sections \
	        -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -ffreestanding
	        
LDFLAGS       = -Wl,-Map,$(PRG).map \
		 -Wl,--gc-sections -Wl,--relax -mmcu=$(DEVICE)

LIBS          = $(LUFA_LIBS)

OBJCOPY        = $(ARCH_PREFIX)objcopy
OBJDUMP        = $(ARCH_PREFIX)objdump

all: $(PRG).elf lst text htool

#avrmon: avrmon.o
#	$(HOST_CC) avrmon.o -o avrmon

#avrmon.o: avrmon.c
#	$(HOST_CC) -c avrmon.c

htool: $(HOST_OBJ)
	$(HOST_LD) $(HOST_LDFLAGS) -o $@ $(HOST_OBJ) $(HOST_LIBS)

lc7981hw.c: ../Library/drivers/lc7981hw.c
	ln -s $< $@

pcf8583-rtc.c: ../Library/drivers/pcf8583-rtc.c
	ln -s $< $@

twi.c: ../Library/drivers/twi.c
	ln -s $< $@

nvram.c: ../Library/drivers/nvram.c
	ln -s $< $@

eeprom.c: ../Library/drivers/eeprom.c
	ln -s $< $@

vss.c: ../Library/drivers/vss.c
	ln -s $< $@

gfx.c: ../Library/gfx/gfx.c
	ln -s $< $@

gfxfont.c: ../Library/gfx/gfxfont.c
	ln -s $< $@

$(PRG).elf: $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)
	$(ARCH_PREFIX)size $(PRG).elf

clean:
	rm -rf *.o $(PRG).elf *.eps *.png *.pdf *.bak *.ho
	rm -rf *.lst *.map $(EXTRA_CLEAN_FILES) main

lst:  $(PRG).lst

%.lst: %.elf
	$(OBJDUMP) -h -S $< > $@

%.o : %.S
	$(CC) -c $(ALL_ASFLAGS) $< -o $@


flash: $(PRG).hex
#	dfu-programmer $(DEVICE) erase || true
#	dfu-programmer $(DEVICE) flash $(PRG).hex
	$(AVRDUDE) -U $(PRG).hex

reset:
	dfu-programmer $(DEVICE) reset


fuse:
	$(AVRDUDE) -U lfuse:w:0xff:m -U hfuse:w:0xd0:m

%.ho: %.c
	$(HOST_CC) $(HOST_CFLAGS) -c $< -o $@

%.ho: %.cpp
	$(HOST_CXX) $(HOST_CXXFLAGS) -c $< -o $@

# Rules for building the .text rom images

text: hex bin srec

hex:  $(PRG).hex
bin:  $(PRG).bin
srec: $(PRG).srec

%.hex: %.elf
	$(OBJCOPY) -j .text -j .data -O ihex $< $@

%.srec: %.elf
	$(OBJCOPY) -j .text -j .data -O srec $< $@

%.bin: %.elf
	$(OBJCOPY) -j .text -j .data -O binary $< $@

# Every thing below here is used by avr-libc's build system and can be ignored
# by the casual user.

JPEGFILES               = stdiodemo-setup.jpg

JPEG2PNM                = jpegtopnm
PNM2EPS                 = pnmtops
JPEGRESOLUTION          = 180
EXTRA_CLEAN_FILES       = *.hex *.bin *.srec *.eps

dox: ${JPEGFILES:.jpg=.eps}

%.eps: %.jpg
	$(JPEG2PNM) $< |\
	$(PNM2EPS) -noturn -dpi $(JPEGRESOLUTION) -equalpixels \
	> $@
