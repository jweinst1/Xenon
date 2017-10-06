#ifndef XENON_ENTYPES_HEADER
#define XENON_ENTYPES_HEADER

enum XenEventType
{
        XenEventType_null, //used as default or for errors
        XenEventType_In,
        XenEventType_Out,
        XenEventType_Add,
        XenEventType_Sub,
        XenEventType_Mul,
        XenEventType_Div,
        XenEventType_Inc,
        XenEventType_Dec
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
        TokzState_Event,
        TokzState_Comment
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
