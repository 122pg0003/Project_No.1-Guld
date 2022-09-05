#include"DxLib.h"
#include"AABB.h"

std::vector<AABBInfo> AABBDraw::aabbInfo;  //実際に使われる変数
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
	//画像が描画されたらその画像のサイズを得て配列に追加する
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

			aabbInfo.emplace_back(aabb);  //画像のX,Y,ハンドルをベクターの配列で保存

#ifdef _DEBUG
			//AABBの範囲の描画
			DrawBox(x, y, x2, y2, GetColor(rand() % 256, rand() % 256, rand() % 256), FALSE);
#endif
		}
	}
	return draw;
}

void AABBDraw::Clear() {
	aabbInfo.clear();  //ベクターの配列を消している
	//handles.clear();
}

//触れたかどうかの判定
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

//クリックされたかの判定
bool AABBDraw::ClickCheck() {
	if (GetMouseInput() & MOUSE_INPUT_LEFT) {
		return true;
	}

	return false;
}

//触れているかどうかの情報の送信
bool AABBDraw::IsTouch() {
	return touch != nullptr;
}

std::shared_ptr<AABBInfo> AABBDraw::GetTouch() {
	return touch;
}

//LOAD_NUMと画像の種類をハンドルの一覧に入れている
bool AABBDraw::SetHandle(LOAD_NUM type, int handle) {
	auto it = handles.find(type);
	if (it != handles.end()) {
		return false;
	}

	handles.emplace(type, handle);
	return true;
}

//ハンドルを探して最後でなければハンドルの情報を返し、最後なら―1を返す
int AABBDraw::GetHandle(LOAD_NUM type) {
	auto it = handles.find(type);
	if (it != handles.end()) {
		return handles[type];
	}

	return -1;
}