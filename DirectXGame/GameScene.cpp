#include "GameScene.h"
#include <cmath>
using namespace KamataEngine;

GameScene::GameScene() {}

GameScene::~GameScene() {
	// デストラクタ
	delete sprite_;
}

void GameScene::Initialize() {

	// ファイル名を指定してテクスチャを読み込む
	textureHandle_ = TextureManager::Load("./Resources/Title/Title.png");

	// スプライトインスタンスの生成
	sprite_ = Sprite::Create(textureHandle_, {0, 0});
}

void GameScene::Update() {

	frameCount++;

	// sin波で上下に揺れるY座標を作る（±10ピクセル範囲で動かす）
	float y = 10 * sin(frameCount * 0.05f);

	// スプライトの位置を更新
	sprite_->SetPosition({0.0f, y});
}

void GameScene::Draw() {
	// DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();
	// スプライト描画前処理
	Sprite::PreDraw(dxCommon->GetCommandList());

	// スプライトインスタンスの描画処理
	if (frameCount % 150 >= 30) {
		sprite_->Draw();
	}

	// スプライト描画後処理
	Sprite::PostDraw();
}