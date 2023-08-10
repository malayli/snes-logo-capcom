ifeq ($(strip $(PVSNESLIB_HOME)),)
$(error "Please create an environment variable PVSNESLIB_HOME with path to its folder and restart application. (you can do it on windows with <setx PVSNESLIB_HOME "/c/snesdev">)")
endif

# BEFORE including snes_rules :
# list in AUDIOFILES all your .it files in the right order. It will build to generate soundbank file
AUDIODIR :=	res
export AUDIOFILES :=	$(foreach dir, $(AUDIODIR), \
	$(dir)/*.it)

# then define the path to generate soundbank data. The name can be different but do not forget to update your include in .c file !
export SOUNDBANK := soundbank

include ${PVSNESLIB_HOME}/devkitsnes/snes_rules

.PHONY: bitmaps all

#---------------------------------------------------------------------------------
# ROMNAME is used in snes_rules file
export ROMNAME := logo

# to build musics, define SMCONVFLAGS with parameters you want
SMCONVFLAGS	:= -s -o $(SOUNDBANK) -V -b 5
musics: $(SOUNDBANK).obj

all: musics bitmaps $(ROMNAME).sfc

cleanGfxLogo:
	@echo clean Logo graphics data
	@rm -f res/*.pic res/*.pal res/*.map res/*.m16 res/*.b16 res/*.o16 res/*.t16

clean: cleanBuildRes cleanRom cleanGfx cleanGfxLogo cleanAudio

#---------------------------------------------------------------------------------
res/logoTileSet.pic: res/logoTileSet.png
	@echo convert map tileset ... $(notdir $@)
	$(GFXCONV) -gs8 -pc16 -po48 -m -fpng -n $<

logoLayerMapBg1.m16: res/logo.json res/logoTileSet.pic
	@echo convert map logo ... $(notdir $@)
	$(TMXCONV) $< res/logoTileSet.map

bitmaps : logoLayerMapBg1.m16 res/logoTileSet.pic
