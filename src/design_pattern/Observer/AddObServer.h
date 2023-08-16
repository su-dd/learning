#ifndef AddObServer_H
#define AddObServer_H
class AddObServer
{
public:
	~AddObServer() {}

	virtual void doAdd(int number) = 0;
};
#endif // !AddObServer_H