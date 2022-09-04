#include"Audio.h"
#include"DxLib.h"

Audio::Audio() {
	Main_Sound = LoadSoundMem("Audio/PerituneMaterial_Windmill_Village_loop (1).mp3");
}

Audio::~Audio() {

}

void Audio::Main_Audio() {
	PlaySoundMem(Main_Sound, DX_PLAYTYPE_BACK,TRUE);
	//PlaySoundFile("Audio/PerituneMaterial_Windmill_Village_loop (1).mp3", DX_PLAYTYPE_BACK);
}