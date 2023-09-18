#include "ScreenManager.h"

ScreenManager* ScreenManager::sInstance = nullptr;

ScreenManager* ScreenManager::Instance() {
	if (sInstance == nullptr) {
		sInstance = new ScreenManager();
	}

	return sInstance;
}

void ScreenManager::Release() {
	delete sInstance;
	sInstance = nullptr;
}

ScreenManager::ScreenManager() {
	m_pScreens.push_back(new StartScreen());
	mCurrentScreen = Start;
}

ScreenManager::~ScreenManager() {
	for (int i = 0; i < m_pScreens.size(); i++) {
		delete m_pScreens[i];
		m_pScreens[i] = nullptr;
	}
}

void ScreenManager::Update() {
	m_pScreens[(int)mCurrentScreen]->Update();
}

void ScreenManager::Render() {
	m_pScreens[(int)mCurrentScreen]->Render();
}
