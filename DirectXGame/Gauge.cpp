#include "Gauge.h"

using namespace KamataEngine;

Gauge::Gauge() {}

Gauge::~Gauge() {}

void Gauge::Initialize() {
	textureHandle_ = TextureManager::Load("./Resources/white1x1.png");

	Vector2 barPos = {50, 50};
	Vector2 barSize = {200, 20};

	// 赤バー（現在HPのみ）
	hpCurrent_ = Sprite::Create(textureHandle_, barPos);
	hpCurrent_->SetSize(barSize); // 初期サイズは最大
	hpCurrent_->SetColor({255, 0, 0, 255});
	hpCurrent_->SetAnchorPoint({0, 0});

	hpRate_ = 1.0f; // 初期HP100%
}

void Gauge::Update() {
	// テスト用：HPを徐々に減らす
	hpRate_ -= 0.001f;
	if (hpRate_ < 0.0f)
		hpRate_ = 0.0f;

	float fullWidth = 200.0f;
	hpCurrent_->SetSize({fullWidth * hpRate_, 20});
}

void Gauge::Draw() {
	if (hpCurrent_) {
		hpCurrent_->Draw();
	}
}
