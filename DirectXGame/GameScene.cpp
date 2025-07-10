#include "GameScene.h"
#include <cmath>
using namespace KamataEngine;

GameScene::GameScene() {}

GameScene::~GameScene() {
	// デストラクタ
	delete sprite_;
	delete Stagesprite_;
	delete player_;
	delete camera_;
}

void GameScene::Initialize() {

	// カメラ生成・初期化
	camera_ = new Camera();
	camera_->Initialize();

	// ファイル名を指定してテクスチャを読み込む
	textureHandle_ = TextureManager::Load("./Resources/Title/Title.png");

	// スプライトインスタンスの生成
	sprite_ = Sprite::Create(textureHandle_, {0, 0});

	Stagesprite_ = new Stage();
	Stagesprite_->Initialize();

	modelPlayer_ = Model::CreateFromOBJ("player", true);
	player_ = new Player();
	player_->Initialize(modelPlayer_, camera_, {0, 0, 0});
}

void GameScene::Update() {

	player_->Update();

	frameCount++;

	if (isTitle) {
		if (isTitle && Input::GetInstance()->TriggerKey(DIK_RETURN)) {
			isTitle = false;

			isBackgroundStarted_ = true;
		}
		// sin波で上下に揺れるY座標を作る（±10ピクセル範囲で動かす）
		float y = 10 * sin(frameCount * 0.05f);
		// スプライトの位置を更新
		sprite_->SetPosition({0.0f, y});
	}

	if (isBackgroundStarted_) {
		Stagesprite_->Update();
	}
}

void GameScene::Draw() {
	// DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();
	// スプライト描画前処理(背景)
	Sprite::PreDraw(dxCommon->GetCommandList());

	if (isBackgroundStarted_) {
		Stagesprite_->Draw();
	}
	// スプライトインスタンスの描画処理
	if (isTitle && frameCount % 150 >= 30) {
		sprite_->Draw();
	}

	// スプライト描画後処理(背景)
	Sprite::PostDraw();

	// 深度バッファクリア
	dxCommon->ClearDepthBuffer();
	// 3Dモデル描画前処理
	Model::PreDraw(dxCommon->GetCommandList());

	player_->Draw();

	// 3Dモデル描画後処理
	Model::PostDraw();

	// スプライト描画前処理(2D近景)
	Sprite::PreDraw(dxCommon->GetCommandList());

	// スプライト描画後処理(背景)
	Sprite::PostDraw();
}