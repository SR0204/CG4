#include "GameScene.h"

using namespace KamataEngine;

GameScene::GameScene() {}

GameScene::~GameScene() {

	// 3Dモデルデータの開放
	delete modelParticle_;

	// パーティクルの解放
	delete particle_;
}

void GameScene::Initialize() {

	// 3Dモデルデータの生成
	modelParticle_ = Model::CreateSphere(4, 4);

	// カメラの初期化
	camera_.Initialize();

	// パーティクルの生成
	particle_ = new Particle();
	// パーティクルの初期化
	particle_->Initialize(modelParticle_);
}

void GameScene::Update() {

	// パーティクルの更新
	particle_->Update();
}

void GameScene::Draw() {

	//DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	//3Dモデル描画処理前
	Model::PreDraw(dxCommon->GetCommandList());

	// パーティクルの描画
	particle_->Draw(camera_);

	//3Dモデル描画処理後
	Model::PostDraw();
}
