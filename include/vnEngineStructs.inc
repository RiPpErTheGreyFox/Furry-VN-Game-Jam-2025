
    IF !DEF(VNENGINESTRUCTS_INC)
DEF VNENGINESTRUCTS_INC EQU 1


INCLUDE "include/structs.inc"

    struct METASPRITE
        bytes 1, YPos ; 1 byte
        bytes 1, XPos ; 1 byte
        bytes 1, XSize ; max of 6
        bytes 1, YSize ; max of 6
        bytes 36, Tiles ; tile indices
    end_struct

    struct CURSOR
        bytes 1, YPos ; 1 byte
        bytes 1, XPos ; 1 byte
        bytes 1, Tile ; 1 byte tile index for drawing/type checking, will be referenced in the update sub
        bytes 1, OAMOffset ; 1 byte which OAM object this will be using to draw to
        bytes 1, Enabled ; 1 byte that will be treated as a bool
    end_struct

    struct PLAYER
        bytes 1, YPos ; 1 byte
        bytes 1, XPos ; 1 byte
        bytes 1, XDestination ; 1 byte
        bytes 1, YDestination ; 1 byte
        bytes 1, TileTL ; 1 byte tile index for drawing, will be referenced in the update sub
        bytes 1, TileTR ; 1 byte
        bytes 1, TileBL ; 1 byte
        bytes 1, TileBR ; 1 byte
        bytes 1, Direction ; 1 byte
        bytes 1, OAMOffset ; 1 byte which OAM object this will be using to draw to
        bytes 1, TileFlags ; 1 byte used to store the OAM flags
        bytes 1, AllowMove ; 1 byte treat as a bool
    end_struct

    struct BOX
        bytes 1, YPos ; 1 byte
        bytes 1, XPos ; 1 byte
        bytes 1, Tile ; 1 byte tile index for drawing/type checking, will be referenced in the update sub
        bytes 1, OAMOffset ; 1 byte which OAM object this will be using to draw to
    end_struct

    
    ENDC ;VNENGINESTRUCTS_INC
