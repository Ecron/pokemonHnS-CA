Route26_House2_MapScripts::
	.byte 0

Route26_House2_EventScript_Book::
	lock
	msgbox DayOfWeekSiblingsHouse_Text_Pokedex1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE,Route26_House2_EventScript_BookRead
	closemessage
	release
	end

Route26_House2_EventScript_BookRead::
	msgbox DayOfWeekSiblingsHouse_Text_Pokedex2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route26_House2_EventScript_BookRead2
	closemessage
	release
	end
	
Route26_House2_EventScript_BookRead2::
	msgbox DayOfWeekSiblingsHouse_Text_Pokedex3, MSGBOX_DEFAULT
	closemessage
	release
	end

DayOfWeekSiblingsHouse_Text_Pokedex1:
    .string "Hi ha alguna cosa escrita.\p"
    .string "Ho llig?$"

DayOfWeekSiblingsHouse_Text_Pokedex2:
    .string "Als meus germans i germanes:\p"
    .string "Estem devanits de servir als\n"
    .string "entrenadors POKéMON.\p"
    .string "Si algun vos parla, doneu-li\n"
    .string "alguna cosa útil.\p"
    .string "Vos estime,\n"
    .string "LLUNA\p"
    .string "Continue llegint-ho?$"

DayOfWeekSiblingsHouse_Text_Pokedex3:
    .string "Dilluns, LLUNA\n"
    .string "RUTA 40\p"
    .string "Dimarts, MARTINA\n"
    .string "RUTA 29\p"
    .string "Dimecres, HERMES\n"
    .string "LLAC DE LA FÚRIA\p"
    .string "Dijous, JUNÍPER\n"
    .string "RUTA 36\p"
    .string "Divendres, VENUS\n"
    .string "RUTA 32\p"
    .string "Dissabte, SATURNÍ\n"
    .string "CIUTAT ARANYÓ\p"
    .string "Diumenge, DOMINICA\n"
    .string "RUTA 37$"
