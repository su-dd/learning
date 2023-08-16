#ifndef VISITOR_H
#define VISITOR_H
class Body;
class Stick;
class Package;
class Visitor
{
public:
	virtual ~Visitor() {}

	virtual void visitor(Body* body) = 0;
	virtual void visitor(Stick* body) = 0;
	virtual void visitor(Package* body) = 0;
};

#endif // !VISITOR_H
