#include "GameScene.h"

using namespace KamataEngine;

GameScene::GameScene() {}

GameScene::~GameScene() { delete sprite_; }

void GameScene::Initialize() {

	// ファイル名を指定してテクスチャを読み込む
	textureHandle_ = TextureManager::Load("Title.png");

	// スプライトインスタンスの生成
	sprite_ = Sprite::Create(textureHandle_, {0, 0});
}

void GameScene::Update() {}

void GameScene::Draw() {

	// DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// スプライト描画前処理
	Sprite::PreDraw(dxCommon->GetCommandList());

	sprite_->Draw();

	// スプライト描画後処理
	Sprite::PostDraw();
}