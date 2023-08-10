.include "hdr.asm"

.section ".rodata1" superfree

logoPic:
.incbin "res/logoTileSet.pic"
logoPic_end:

logoPalette:
.incbin "res/logoTileSet.pal"

.ends

.section ".rodata2" superfree

logoLayerMap:
.incbin "res/logoLayerMapBg1.m16"

logoTilesProp:
.incbin "res/logo.b16"

logoTilesDef:
.incbin "res/logo.t16"

.ends