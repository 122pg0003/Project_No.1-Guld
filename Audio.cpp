#include"Audio.h"
#include"DxLib.h"


Audio::Audio() {
	Main_Sound = LoadSoundMem("Audio/PerituneMaterial_Windmill_Village_loop (1).mp3");
	Click      = LoadSoundMem("Audio/Œˆ’èƒ{ƒ^ƒ“‚ð‰Ÿ‚·48.mp3");
}


Audio::~Audio() {

}


void Audio::Main_Audio() {
	PlaySoundMem(Main_Sound, DX_PLAYTYPE_LOOP, TRUE);
	//PlaySoundFile("Audio/PerituneMaterial_Windmill_Village_loop (1).mp3", DX_PLAYTYPE_BACK);
}


void Audio::Check_Click() {
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0){
		PlaySoundMem(Click, DX_PLAYTYPE_BACK, TRUE);
}
}