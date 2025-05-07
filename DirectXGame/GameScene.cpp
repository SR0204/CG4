#include "GameScene.h"

using namespace KamataEngine;

GameScene::GameScene() {}

GameScene::~GameScene() { delete effect_; }

void GameScene::Initialize() {

	// 3Dモデルデータの生成
	modelEffect_ = Model::CreateFromOBJ("effect",true);

	// カメラの初期化
	camera_.Initialize();

	// エフェクト
	effect_ = new Effect();
	effect_->Initialize(modelEffect_);
}

void GameScene::Update() { effect_->Update(); }

void GameScene::Draw() {

	// DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// 3Dモデル描画処理前
	Model::PreDraw(dxCommon->GetCommandList());

	effect_->Draw(camera_);

	// 3Dモデル描画処理後
	Model::PostDraw();
}
