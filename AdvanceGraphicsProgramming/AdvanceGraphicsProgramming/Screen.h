#ifndef _SCREEN_H
#define _SCREEN_H

class Screen
{
public:
	virtual void SinglePlayer() {};
	virtual void Update() = 0;
	virtual void Render() = 0;
};

#endif // !_SCREEN_H