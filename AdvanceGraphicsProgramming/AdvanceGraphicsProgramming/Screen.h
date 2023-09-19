#ifndef SCREEN_H
#define SCREEN_H

class Screen
{
public: // SHARED DOERS
	virtual void SinglePlayer() {};
	virtual void Update() = 0;
	virtual void Render() = 0;
};
#endif // !SCREEN_H