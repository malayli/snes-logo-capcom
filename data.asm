.include "hdr.asm"

.section ".rodata1" superfree

logoPic:
.incbin "res/logo.pic"
logoPic_end:

logoPalette:
.incbin "res/logo.pal"
logoPalette_end:

Mapsc:
.incbin "res/clouds.map"
Mapsc_end:

CloudTiles:
.incbin "res/clouds.pic"
CloudTiles_end:

CloudPalette:
.incbin "res/clouds.pal"
CloudPalette_end:

.ends
