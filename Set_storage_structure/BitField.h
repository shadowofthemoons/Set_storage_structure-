#pragma once
typedef unsigned int uint;
class TBitField
{
private:
	int BitLen; // ����� �������� ���� - ����. �-�� �����
	uint *pMem; // ������ ��� ������������� �������� ����
	int MemLen; // �-�� ��-��� ��� ��� ������������� ���.����
	// ������ ����������
//	int GetMemIndex(const int n) const; // ������ � p��� ��� ���� n
//	uint GetMemMask(const int n) const; // ������� ����� ��� ���� n
public:
	TBitField(int len);
	TBitField(const TBitField &bf);
	~TBitField();
	// ������ � �����
	//int GetLength(void) const; // �������� ����� (�-�� �����)
//void SetBit(const int n); // ���������� ���
//	void ClrBit(const int n); // �������� ���
//	int GetBit(const int n) const; // �������� �������� ����
	// ������� ��������
//	int operator==(const TBitField &bf); // ���������
	//TBitField& operator=(const TBitField &bf); // ������������
//	TBitField operator|(const TBitField &bf); // �������� "���"
//	TBitField operator&(const TBitField &bf); // �������� "�"
//	TBitField operator~(void); // ���������
	//friend istream &operator>>(istream &istr, TBitField &bf);
	//friend ostream &operator<<(ostream &ostr, const TBitField &bf);
};

