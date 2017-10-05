#ifndef XENON_ENTYPES_HEADER
#define XENON_ENTYPES_HEADER

enum XenEventType
{
        XenEventType_In,
        XenEventType_Out,
        XenEventType_Add
};

enum XenType
{
        XenType_Number
};

enum XenErrType
{
        XenErrType_EventName
};

//state tracking for tokenizer
enum TokzState
{
        TokzState_Base,
        TokzState_Comment,
        TokzState_EventName,
        TokzState_Number
};

//states for Xenon parser
enum ParseState
{
        ParseState_Base
};

//denotes type of token
enum TokenType
{
        TokenType_EventStart,
        TokenType_EventEnd,
        TokenType_Number
};

#endif
