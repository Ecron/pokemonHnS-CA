EventScript_Dresser::
    lockall
    msgbox Text_ChangeClothes, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, EventScript_CloseDresser
    message Text_ChooseRegionStyle
    waitmessage
    multichoicedefault 0, 0, MULTI_DRESSER_DRAWERS, 3, FALSE
    switch VAR_RESULT
    case 0, EventScript_GoldCostumes
    case 1, EventScript_KrisCostumes
    case 2, EventScript_Dresser_Exit
    case MULTI_B_PRESSED, EventScript_Dresser_Exit
    releaseall
    end

Text_ChangeClothes:
    .string "It's full of clean clothes!\p"
    .string "Would you like to change?$"

Text_ChooseRegionStyle:
    .string "Which drawer do you want to\n"
    .string "to choose an outfit from?$"

EventScript_CloseDresser::
    closemessage
    releaseall
    end

EventScript_Dresser_Exit::
    closemessage
    msgbox Text_ChangeClothes_Cancel, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, FALSE, EventScript_Dresser_Loop
    releaseall
    end

Text_ChangeClothes_Cancel:
    .string "Would you like to keep\n"
    .string "your current outfit?$"

EventScript_Dresser_Loop::
    message Text_ChooseRegionStyle
    waitmessage
    multichoicedefault 0, 0, MULTI_DRESSER_DRAWERS, 3, FALSE
    switch VAR_RESULT
    case 0, EventScript_GoldCostumes
    case 1, EventScript_KrisCostumes
    case 2, EventScript_Dresser_Exit
    case MULTI_B_PRESSED, EventScript_Dresser_Exit
    end

Text_ChooseOutfit:
    .string "There are lots of options!\n"
    .string "Choose a style!$"

EventScript_GoldCostumes::
    msgbox Text_ChooseOutfit
    waitmessage
    multichoicedefault 0, 0, MULTI_GOLD_COSTUMES, 3, FALSE
    switch VAR_RESULT
    case 0, EventScript_CostumeSwap_Gold_OG
    case 1, EventScript_CostumeSwap_Gold_Alt
    case 2, EventScript_Dresser_Loop
    case MULTI_B_PRESSED, EventScript_Dresser_Loop
    end

EventScript_CostumeSwap_Gold_OG::
    lockall
    fadescreen FADE_TO_BLACK
    setvar VAR_TEMP_1, GOLDOG_COSTUME
    special SwapPlayersCostume
    fadescreen FADE_FROM_BLACK
    goto EventScript_Dresser_Finish
    end

EventScript_CostumeSwap_Gold_Alt::
    lockall
    fadescreen FADE_TO_BLACK
    setvar VAR_TEMP_1, GOLDALT_COSTUME
    special SwapPlayersCostume
    fadescreen FADE_FROM_BLACK
    goto EventScript_Dresser_Finish
    end


EventScript_KrisCostumes::
    msgbox Text_ChooseOutfit
    waitmessage
    multichoicedefault 0, 0, MULTI_KRIS_COSTUMES, 3, FALSE
    switch VAR_RESULT
    case 0, EventScript_CostumeSwap_Kris_OG
    case 1, EventScript_CostumeSwap_Kris_Alt
    case 2, EventScript_Dresser_Loop
    case MULTI_B_PRESSED, EventScript_Dresser_Loop
    end

EventScript_CostumeSwap_Kris_OG::
    lockall
    fadescreen FADE_TO_BLACK
    setvar VAR_TEMP_1, KRISOG_COSTUME
    special SwapPlayersCostume
    fadescreen FADE_FROM_BLACK
    goto EventScript_Dresser_Finish
    end

EventScript_CostumeSwap_Kris_Alt::
    lockall
    fadescreen FADE_TO_BLACK
    setvar VAR_TEMP_1, KRISALT_COSTUME
    special SwapPlayersCostume
    fadescreen FADE_FROM_BLACK
    goto EventScript_Dresser_Finish
    end

// These are place holders for a future holiday costume expansion
//EventScript_HolidayCostumes::
    //msgbox Text_ChooseOutfit
    //waitmessage
    //multichoicedefault 0, 0, MULTI_HOENN_COSTUMES, 3, FALSE
    //switch VAR_RESULT
    //case 0, EventScript_CostumeSwap_Brendan
    //case 1, EventScript_CostumeSwap_May
    //case 2, EventScript_Dresser_Loop
    //case MULTI_B_PRESSED, EventScript_Dresser_Loop
    //end

//EventScript_CostumeSwap_Brendan::
    //lockall
    //fadescreen FADE_TO_BLACK
    //setvar VAR_TEMP_1, BRENDAN_COSTUME
    //special SwapPlayersCostume
    //fadescreen FADE_FROM_BLACK
    //goto EventScript_Dresser_Finish
    //end

//EventScript_CostumeSwap_May::
    //lockall
    //fadescreen FADE_TO_BLACK
    //setvar VAR_TEMP_1, MAY_COSTUME
    //special SwapPlayersCostume
    //fadescreen FADE_FROM_BLACK
    //goto EventScript_Dresser_Finish
    //end

EventScript_Dresser_Finish::
    closemessage
    msgbox Text_ChangeClothes_Confirm, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, FALSE, EventScript_Dresser_Loop
    msgbox Text_ChangeClothes_Finished, MSGBOX_DEFAULT
    releaseall
    end

Text_ChangeClothes_Confirm:
    .string "Wear this outfit?$"

Text_ChangeClothes_Finished:
    .string "Lookin' good!$"
