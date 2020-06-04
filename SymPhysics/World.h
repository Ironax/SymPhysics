#pragma once

namespace Sym
{
	extern "C++" class __declspec(dllexport) World
	{
	public:
		World();
        ~World();

		void Init();
	};
}