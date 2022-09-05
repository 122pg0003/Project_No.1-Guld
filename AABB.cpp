#include"DxLib.h"
#include"AABB.h"

std::vector<AABBInfo> AABBDraw::aabbInfo;  //���ۂɎg����ϐ�
std::shared_ptr<AABBInfo> AABBDraw::touch;
std::map<AABBDraw::LOAD_NUM, int> AABBDraw::handles;

AABBInfo::AABBInfo() {
	X = -1;
	Y = -1;
	X2 = -1;
	Y2 = -1;
	Handle = -1;
}

AABBInfo::AABBInfo(const AABBInfo& info) {
	X = info.X;
	Y = info.Y;
	X2 = info.X2;
	Y2 = info.Y2;
	Handle = info.Handle;
}

AABBInfo::~AABBInfo() {

}

AABBDraw::AABBDraw() {
}

AABBDraw::~AABBDraw() {

}

int AABBDraw::MyDrawGraph(int x, int y, int GrHandle, int TransFlag) {




	int draw = DrawGraph(x, y, GrHandle, TransFlag);
	//�摜���`�悳�ꂽ�炻�̉摜�̃T�C�Y�𓾂Ĕz��ɒǉ�����
	if (draw != -1) {
		int Width = 0;
		int Height = 0;

		if (-1 != GetGraphSize(GrHandle, &Width, &Height))
		{
			int x2 = x + Width;
			int y2 = y + Height;

			AABBInfo aabb;

			aabb.X = x;
			aabb.Y = y;
			aabb.X2 = x2;
			aabb.Y2 = y2;
			aabb.Handle = GrHandle;

			aabbInfo.emplace_back(aabb);  //�摜��X,Y,�n���h�����x�N�^�[�̔z��ŕۑ�

#ifdef _DEBUG
			//AABB�͈̔͂̕`��
			DrawBox(x, y, x2, y2, GetColor(rand() % 256, rand() % 256, rand() % 256), FALSE);
#endif
		}
	}
	return draw;
}

void AABBDraw::Clear() {
	aabbInfo.clear();  //�x�N�^�[�̔z��������Ă���
	//handles.clear();
}

//�G�ꂽ���ǂ����̔���
bool AABBDraw::TouchCheck() {
	touch = nullptr;

	int MouseX, MouseY;

	GetMousePoint(&MouseX, &MouseY);
	for (int i = aabbInfo.size() - 1; i >= 0; --i) {

		AABBInfo& info = aabbInfo[i];


		if ((MouseX > info.X) &&
			(MouseX < info.X2) &&
			(MouseY > info.Y) &&
			(MouseY < info.Y2)) {

			touch.reset(new AABBInfo(info));
			return true;
		}

	}

	return false;
}

//�N���b�N���ꂽ���̔���
bool AABBDraw::ClickCheck() {
	if (GetMouseInput() & MOUSE_INPUT_LEFT) {
		return true;
	}

	return false;
}

//�G��Ă��邩�ǂ����̏��̑��M
bool AABBDraw::IsTouch() {
	return touch != nullptr;
}

std::shared_ptr<AABBInfo> AABBDraw::GetTouch() {
	return touch;
}

//LOAD_NUM�Ɖ摜�̎�ނ��n���h���̈ꗗ�ɓ���Ă���
bool AABBDraw::SetHandle(LOAD_NUM type, int handle) {
	auto it = handles.find(type);
	if (it != handles.end()) {
		return false;
	}

	handles.emplace(type, handle);
	return true;
}

//�n���h����T���čŌ�łȂ���΃n���h���̏���Ԃ��A�Ō�Ȃ�\1��Ԃ�
int AABBDraw::GetHandle(LOAD_NUM type) {
	auto it = handles.find(type);
	if (it != handles.end()) {
		return handles[type];
	}

	return -1;
}