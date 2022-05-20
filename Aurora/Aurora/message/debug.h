#pragma once

#pragma warning(disable: 4100)

#define DebugMessage(msg, ...) DbgPrintEx(0, 0, msg, __VA_ARGS__) // bugged?

