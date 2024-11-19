module Drv {
    enum Location {
        SQ_A1 = 1
        SQ_B1 = 2
        SQ_C1 = 3
        SQ_D1 = 4
        SQ_E1 = 5
        SQ_F1 = 6
        SQ_G1 = 7
        SQ_H1 = 8
        SQ_A2 = 9
        SQ_B2 = 10
        SQ_C2 = 11
        SQ_D2 = 12
        SQ_E2 = 13
        SQ_F2 = 14
        SQ_G2 = 15
        SQ_H2 = 16
        SQ_A3 = 17
        SQ_B3 = 18
        SQ_C3 = 19
        SQ_D3 = 20
        SQ_E3 = 21
        SQ_F3 = 22
        SQ_G3 = 23
        SQ_H3 = 24
        SQ_A4 = 25
        SQ_B4 = 26
        SQ_C4 = 27
        SQ_D4 = 28
        SQ_E4 = 29
        SQ_F4 = 30
        SQ_G4 = 31
        SQ_H4 = 32
        SQ_A5 = 33
        SQ_B5 = 34
        SQ_C5 = 35
        SQ_D5 = 36
        SQ_E5 = 37
        SQ_F5 = 38
        SQ_G5 = 39
        SQ_H5 = 40
        SQ_A6 = 41
        SQ_B6 = 42
        SQ_C6 = 43
        SQ_D6 = 44
        SQ_E6 = 45
        SQ_F6 = 46
        SQ_G6 = 47
        SQ_H6 = 48
        SQ_A7 = 49
        SQ_B7 = 50
        SQ_C7 = 51
        SQ_D7 = 52
        SQ_E7 = 53
        SQ_F7 = 54
        SQ_G7 = 55
        SQ_H7 = 56
        SQ_A8 = 57
        SQ_B8 = 58
        SQ_C8 = 59
        SQ_D8 = 60
        SQ_E8 = 61
        SQ_F8 = 62
        SQ_G8 = 63
        SQ_H8 = 64
        NO_SQ = 65
    }

    port movePiece(
        startPos: Location
        endPos: Location
    )
}
