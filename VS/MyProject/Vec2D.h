#pragma once
class Vec2D{
public:
	Vec2D();
	Vec2D(double, double);
	~Vec2D();
private:
	double x_;
	double y_;
public:
	// ������ת��Ϊ�ַ�����ʽ��ʾ
	std::string toString();
	// �ӷ�
	Vec2D add(Vec2D secondVec2D);
};

