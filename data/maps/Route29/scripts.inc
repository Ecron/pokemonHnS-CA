Route29_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route29_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route29_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route29_Trigger_Monview::
	special SpawnCameraObject
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1 
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1
	waitmovement 0
	message Route29_Text_PressAorB
	waitbuttonpress
	closemessage
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	special RemoveCameraObject
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	end

Route29_Text_PressAorB:
	.string "Prem A o B per a deixar de veure.$"

Route29_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, Route29_EventScript_OldMan2
	msgbox Route29_Text_OldMan1, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_OldMan2::
	msgbox Route29_Text_OldMan2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route29_EventScript_OldMan_Tutorial
	waitmessage
	msgbox Route29_Text_OldManDeclined, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_OldMan_Tutorial::
	msgbox Route29_Text_OldManExplanation, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Lass::
	lock
	faceplayer
	msgbox Route29_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Youngster::
	lock
	faceplayer
	msgbox Route29_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end


Route29_EventScript_Tuscany::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SILK_SCARF, Route29_EventScript_TuscanyCompleted
	msgbox Route29_Text_MeetTuscany, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route29_EventScript_TuscanyNope
	case 1, Route29_EventScript_TuscanyNope
	case 2, Route29_EventScript_TuscanyYes
	case 3, Route29_EventScript_TuscanyNope
	case 4, Route29_EventScript_TuscanyNope
	case 5, Route29_EventScript_TuscanyNope
	case 6, Route29_EventScript_TuscanyNope
	case 7 Route29_EventScript_TuscanyCancel
	case MULTI_B_PRESSED, Route29_EventScript_TuscanyCancel
	closemessage
	release
	end
Route29_EventScript_TuscanyYes::
	msgbox Route29_Text_TuscanyGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_SILK_SCARF
	msgbox Route29_Text_TuscanyGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route29_EventScript_TuscanyNope::
	msgbox Route29_Text_TuscanyNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route29_EventScript_TuscanyCancel::
	closemessage
	release
	end
Route29_EventScript_TuscanyCompleted::
	msgbox Route29_Text_TuscanyTuesday, MSGBOX_DEFAULT
	closemessage
	release
	end



Route29_EventScript_Girl::
	lock
	faceplayer
	msgbox Route29_Text_Girl, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_NIGHT_POKEMON, Route29_EventScript_Boy2
	msgbox Route29_Text_Boy_WaitingForDay, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Boy2::
	msgbox Route29_Text_Boy_WaitingForNight, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Sign::
	lock
	msgbox Route29_Text_Sign1, MSGBOX_SIGN
	closemessage
	release
	end

Route29_EventScript_ItemPotion::
	finditem ITEM_POTION
	end

Route29_Text_OldMan1:
	.string "Els POKéMON s'amaguen en l'herba.\n"
	.string "Poden aparéixer en qualsevol moment…$"

Route29_Text_OldMan2:
	.string "Ja t'he vist un parell de vegades.\n"
	.string "Quants POKéMON has capturat?\p"
	.string "Vols que t'explique com es fa\n"
	.string "per a capturar POKéMON?$"

Route29_Text_OldManExplanation:
	.string "Si els debilites primer,\n"
	.string "és més fàcil capturar-los.\p"
	.string "Aleshores, llança'ls una POKéBALL\n"
	.string "de la motxilla! Tria'n el tipus que vulgues.\p"
	.string "Si vols aprendre'n més,\n"
	.string "vés a l'ACADÈMIA en CIUTAT MALVA!\p"
	.string "Allà els estudiants en saben molt,\n"
	.string "sobre els POKéMON.$"

Route29_Text_OldManDeclined:
	.string "Ah. Bé, com vulgues.\p"
	.string "Investiga cada ruta per a trobar\n"
	.string "tipus de POKéMON diferents.\p"
	.string "També pots consultar en la POKéDEX\n"
	.string "on els pots trobar!\p"
	.string "Si vols aprendre'n més,\n"
	.string "vés a l'ACADÈMIA en CIUTAT MALVA!\p"
	.string "Allà els estudiants en saben molt,\n"
	.string "sobre els POKéMON.$"

Route29_Text_Youngster:
	.string "Ie. Com estan els teus POKéMON?\p"
	.string "Si estan dèbils i no poden lluitar,\n"
	.string "no vages per l'herba.$"

Route29_Text_Lass:
	.string "Veus aquelles ribes?\n"
	.string "Fa por botar des de dalt.\p"
	.string "Però pots anar a POBLE BORRÓ\n"
	.string "sense haver de caminar per l'herba.$"

Route29_Text_Girl:
	.string "Volia fer un descans i guardar\n"
	.string "la partida, per a no perdre el progrés.$"

Route29_Text_Boy_WaitingForDay:
	.string "Estic esperant als POKéMON que\n"
	.string "només apareixen a mitjan vesprada.$"

Route29_Text_Boy_WaitingForNight:
	.string "Estic esperant als POKéMON que\n"
	.string "només apareixen de nit.$"

Route29_Text_MeetTuscany:
	.string "TUSCANY: I do believe that this\n"
	.string "is the first time we've met?\p"
	.string "I'm TUSCANY of the WEEKDAY FAMILY.\p"
	.string "If you can guess my favorite day,\n"
	.string "I'll give you a reward.$"

Route29_Text_TuscanyNope:
	.string "Not quite!$"

Route29_Text_TuscanyGivesGift:
	.string "Yes! By way of introduction,\n"
	.string "please accept this gift, a SILK\l"
	.string "SCARF.$"

Route29_Text_TuscanyGaveGift:
	.string "TUSCANY: Wouldn't you agree\n"
	.string "that it is most adorable?\p"
	.string "It strengthens NORMAL-type\n"
	.string "moves.\p"
	.string "I am certain it will be of use.$"

Route29_Text_TuscanyTuesday:
	.string "TUSCANY: Have you met MONICA,\n"
	.string "my older sister?\p"
	.string "Or my younger brother, WESLEY?\p"
	.string "I am the third of seven\n"
	.string "children.$"

Route29_Text_Sign1:
	.string "ROUTE 29\p"
	.string "CHERRYGROVE CITY - NEW BARK TOWN$"

