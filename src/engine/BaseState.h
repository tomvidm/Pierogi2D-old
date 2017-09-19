/*
	Base State is an awesome thing because I say so.
	SJUR ARNE SJOFLOT
*/

namespace engine
{
	class BaseState
	{
	public:
		virtual void someCommonInterfaceMethod();
		virtual void doTasks();
		virtual void sjurArneSjoflot(int goma);
	private:
		int someVar;
	};
}