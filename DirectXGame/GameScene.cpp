#include "GameScene.h"
#include <random>

using namespace KamataEngine;
using namespace MathUtility;

std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);

GameScene::GameScene() {}

GameScene::~GameScene() {

	delete modelEffect_;

	// エフェクトの開放
	for (Effect* effect : effects_) {
		delete effect;
	}
	effects_.clear();
}

void GameScene::Initialize() {

	// 3Dモデルデータの生成
	modelEffect_ = Model::CreateFromOBJ("effect", true);

	// カメラの初期化
	camera_.Initialize();

	// エフェクト
	for (int i = 0; i < 10; i++) {

		// 生成
		Effect* effect = new Effect();
		// 位置
		Vector3 rotation = {0.0f, 0.0f, 0.0f};
		// 移動量
		Vector3 velocity = {distribution(randomEngine), distribution(randomEngine), 0};
		Normalize(velocity);
		velocity *= distribution(randomEngine);
		velocity *= 0.2f;

		// 初期化
		effect->Initialize(modelEffect_, rotation, velocity);
		// リストに追加
		effects_.push_back(effect);
	}
}

void GameScene::Update() {

	// エフェクトの更新
	for (Effect* effect : effects_) {
		effect->Update();
	}

	// 終了フラグの立ったパーティクルを削除
	effects_.remove_if([](Effect* effect) {
		if (effect->IsFinished()) {
			delete effect;
			return true;
		}
		return false;
	});
}

void GameScene::Draw() {

	// DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// 3Dモデル描画処理前
	Model::PreDraw(dxCommon->GetCommandList());

	// エフェクトの描画
	for (Effect* effect : effects_) {
		effect->Draw(camera_);
	}

	// 3Dモデル描画処理後
	Model::PostDraw();
}
