#include "Stage.h"

using namespace KamataEngine;

Stage::Stage() {}

Stage::~Stage() {

	delete sprite1_;
}

void Stage::Initialize() {
	textureHandle_ = TextureManager::Load("./Resources/Stage/Stage.png");

	// 通常向き
	sprite1_ = Sprite::Create(textureHandle_, {0, 0});

	// ミラー（X反転）
	sprite2_ = Sprite::Create(textureHandle_, {bgWidth_, 0});
	sprite2_->GetIsFlipX(); // 左右反転（ミラー）
}

void Stage::Update() {
	scrollX_ += scrollSpeed_;

	// 画像幅分でループ
	if (scrollX_ >= bgWidth_) {
		scrollX_ -= bgWidth_;
	}

	// ミラーで連続配置
	sprite1_->SetPosition({-scrollX_, 0});
	sprite2_->SetPosition({-scrollX_ + bgWidth_, 0});
}

void Stage::Draw() {

	sprite1_->Draw();
	sprite2_->Draw();
}
