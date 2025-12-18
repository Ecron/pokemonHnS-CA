NewBarkTown_House1_MapScripts::
	.byte 0

NewBarkTown_House1_EventScript_Mother::
	lock
	faceplayer
	msgbox NewBarkTown_House1_Text_Neighbor, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House1_EventScript_Daughter::
	lock
	faceplayer
	msgbox NewBarkTown_House1_Text_NeighborsDaughter, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House1_Text_NeighborsDaughter:
	.string "PIKATXU és un POKéMON evolucionat.\p"
	.string "Em meravellen les troballes\n"
	.string "del PROF. XOP.\p"
	.string "És molt famós per la seua investigació\n"
	.string "sobre l'evolució dels POKéMON.\p"
	.string "… ai…\p"
	.string "Com m'agradaria ser una investigadora\n"
	.string "com ell…$"


NewBarkTown_House1_Text_Neighbor:
	.string "La meua filla s'ha encabotat en\n"
	.string "ser l'ajudant del PROF. XOP.\p"
	.string "Li encanten els POKéMON!\p"
	.string "I a mi també!$"

