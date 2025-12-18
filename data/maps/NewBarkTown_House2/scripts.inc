NewBarkTown_House2_MapScripts::
	.byte 0


NewBarkTown_House2_EventScript_ElmsWife::
	lock
	faceplayer
	msgbox NewBarkTown_House2_Text_ElmsWife, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House2_EventScript_ElmsSon::
	lock
	faceplayer
	msgbox NewBarkTown_House2_Text_ElmsSon, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House2_Text_ElmsWife:
	.string "Com va, {PLAYER}! El meu home està sempre\n"
	.string "tan afaenat… Espere que estiga bé.\p"
	.string "Quan s'engresca en la seua\n"
	.string "investigació POKéMON, fins i tot\l"
	.string "se li oblida menjar.$"

NewBarkTown_House2_Text_ElmsSon:
	.string "Quan siga major, ajudaré\n"
	.string "a mon pare!\p"
	.string "Em convertiré en un gran\n"
	.string "professor POKéMON!$"
