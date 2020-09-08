
// Generated from SimpleSMTLIBLexer.g4 by ANTLR 4.8


#include "SimpleSMTLIBLexer.h"


using namespace antlr4;


SimpleSMTLIBLexer::SimpleSMTLIBLexer(CharStream *input) : Lexer(input) {
  _interpreter = new atn::LexerATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

SimpleSMTLIBLexer::~SimpleSMTLIBLexer() {
  delete _interpreter;
}

std::string SimpleSMTLIBLexer::getGrammarFileName() const {
  return "SimpleSMTLIBLexer.g4";
}

const std::vector<std::string>& SimpleSMTLIBLexer::getRuleNames() const {
  return _ruleNames;
}

const std::vector<std::string>& SimpleSMTLIBLexer::getChannelNames() const {
  return _channelNames;
}

const std::vector<std::string>& SimpleSMTLIBLexer::getModeNames() const {
  return _modeNames;
}

const std::vector<std::string>& SimpleSMTLIBLexer::getTokenNames() const {
  return _tokenNames;
}

dfa::Vocabulary& SimpleSMTLIBLexer::getVocabulary() const {
  return _vocabulary;
}

const std::vector<uint16_t> SimpleSMTLIBLexer::getSerializedATN() const {
  return _serializedATN;
}

const atn::ATN& SimpleSMTLIBLexer::getATN() const {
  return _atn;
}




// Static vars and initialization.
std::vector<dfa::DFA> SimpleSMTLIBLexer::_decisionToDFA;
atn::PredictionContextCache SimpleSMTLIBLexer::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN SimpleSMTLIBLexer::_atn;
std::vector<uint16_t> SimpleSMTLIBLexer::_serializedATN;

std::vector<std::string> SimpleSMTLIBLexer::_ruleNames = {
  u8"ParOpen", u8"ParClose", u8"PS_And", u8"PS_Or", u8"PS_Not", u8"PS_Eq", 
  u8"PS_Lt", u8"PS_Le", u8"PS_Gt", u8"PS_Ge", u8"PS_Add", u8"PS_Sub", u8"PS_Div", 
  u8"PS_Mul", u8"PIPE", u8"DOUBLE_QUOTE", u8"PS_False", u8"PS_True", u8"GRW_Binary", 
  u8"GRW_Decimal", u8"GRW_Exists", u8"GRW_Hexadecimal", u8"GRW_Forall", 
  u8"GRW_Let", u8"GRW_Match", u8"GRW_Numeral", u8"GRW_Par", u8"GRW_String", 
  u8"GRW_Ite", u8"Numeral", u8"Binary", u8"HexDecimal", u8"Decimal", u8"HexDigit", 
  u8"Digit", u8"Sym", u8"BinaryDigit", u8"UndefinedSymbol", u8"WHITESPACE"
};

std::vector<std::string> SimpleSMTLIBLexer::_channelNames = {
  "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
};

std::vector<std::string> SimpleSMTLIBLexer::_modeNames = {
  u8"DEFAULT_MODE"
};

std::vector<std::string> SimpleSMTLIBLexer::_literalNames = {
  "", u8"'('", u8"')'", u8"'and'", u8"'or'", u8"'not'", u8"'='", u8"'<'", 
  u8"'<='", u8"'>'", u8"'>='", u8"'+'", u8"'-'", u8"'/'", u8"'*'", u8"'|'", 
  u8"'\"'", u8"'false'", u8"'true'", u8"'BINARY'", u8"'DECIMAL'", u8"'exists'", 
  u8"'HEXADECIMAL'", u8"'forall'", u8"'let'", u8"'match'", u8"'NUMERAL'", 
  u8"'par'", u8"'string'", u8"'ite'"
};

std::vector<std::string> SimpleSMTLIBLexer::_symbolicNames = {
  "", u8"ParOpen", u8"ParClose", u8"PS_And", u8"PS_Or", u8"PS_Not", u8"PS_Eq", 
  u8"PS_Lt", u8"PS_Le", u8"PS_Gt", u8"PS_Ge", u8"PS_Add", u8"PS_Sub", u8"PS_Div", 
  u8"PS_Mul", u8"PIPE", u8"DOUBLE_QUOTE", u8"PS_False", u8"PS_True", u8"GRW_Binary", 
  u8"GRW_Decimal", u8"GRW_Exists", u8"GRW_Hexadecimal", u8"GRW_Forall", 
  u8"GRW_Let", u8"GRW_Match", u8"GRW_Numeral", u8"GRW_Par", u8"GRW_String", 
  u8"GRW_Ite", u8"Numeral", u8"Binary", u8"HexDecimal", u8"Decimal", u8"UndefinedSymbol", 
  u8"WHITESPACE"
};

dfa::Vocabulary SimpleSMTLIBLexer::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> SimpleSMTLIBLexer::_tokenNames;

SimpleSMTLIBLexer::Initializer::Initializer() {
  // This code could be in a static initializer lambda, but VS doesn't allow access to private class members from there.
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x2, 0x25, 0x102, 0x8, 0x1, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 
    0x4, 0x4, 0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 
    0x9, 0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
    0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 
    0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 
    0x11, 0x4, 0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 
    0x4, 0x15, 0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 
    0x18, 0x9, 0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 
    0x9, 0x1b, 0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 
    0x1e, 0x4, 0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 
    0x4, 0x22, 0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 
    0x25, 0x9, 0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 
    0x9, 0x28, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 
    0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 
    0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 
    0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 
    0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 
    0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1f, 
    0x3, 0x1f, 0x3, 0x1f, 0x7, 0x1f, 0xd1, 0xa, 0x1f, 0xc, 0x1f, 0xe, 0x1f, 
    0xd4, 0xb, 0x1f, 0x5, 0x1f, 0xd6, 0xa, 0x1f, 0x3, 0x20, 0x6, 0x20, 0xd9, 
    0xa, 0x20, 0xd, 0x20, 0xe, 0x20, 0xda, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 0x3, 
    0x22, 0x3, 0x22, 0x7, 0x22, 0xe8, 0xa, 0x22, 0xc, 0x22, 0xe, 0x22, 0xeb, 
    0xb, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 
    0x24, 0x3, 0x25, 0x5, 0x25, 0xf4, 0xa, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 
    0x27, 0x3, 0x27, 0x3, 0x27, 0x6, 0x27, 0xfb, 0xa, 0x27, 0xd, 0x27, 0xe, 
    0x27, 0xfc, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x2, 0x2, 0x29, 
    0x3, 0x3, 0x5, 0x4, 0x7, 0x5, 0x9, 0x6, 0xb, 0x7, 0xd, 0x8, 0xf, 0x9, 
    0x11, 0xa, 0x13, 0xb, 0x15, 0xc, 0x17, 0xd, 0x19, 0xe, 0x1b, 0xf, 0x1d, 
    0x10, 0x1f, 0x11, 0x21, 0x12, 0x23, 0x13, 0x25, 0x14, 0x27, 0x15, 0x29, 
    0x16, 0x2b, 0x17, 0x2d, 0x18, 0x2f, 0x19, 0x31, 0x1a, 0x33, 0x1b, 0x35, 
    0x1c, 0x37, 0x1d, 0x39, 0x1e, 0x3b, 0x1f, 0x3d, 0x20, 0x3f, 0x21, 0x41, 
    0x22, 0x43, 0x23, 0x45, 0x2, 0x47, 0x2, 0x49, 0x2, 0x4b, 0x2, 0x4d, 
    0x24, 0x4f, 0x25, 0x3, 0x2, 0x8, 0x3, 0x2, 0x33, 0x3b, 0x5, 0x2, 0x32, 
    0x3b, 0x43, 0x48, 0x63, 0x68, 0x3, 0x2, 0x32, 0x3b, 0x7, 0x2, 0x23, 
    0x23, 0x26, 0x26, 0x43, 0x5c, 0x61, 0x61, 0x63, 0x7c, 0x3, 0x2, 0x32, 
    0x33, 0x5, 0x2, 0xb, 0xc, 0xe, 0xf, 0x22, 0x22, 0x2, 0x104, 0x2, 0x3, 
    0x3, 0x2, 0x2, 0x2, 0x2, 0x5, 0x3, 0x2, 0x2, 0x2, 0x2, 0x7, 0x3, 0x2, 
    0x2, 0x2, 0x2, 0x9, 0x3, 0x2, 0x2, 0x2, 0x2, 0xb, 0x3, 0x2, 0x2, 0x2, 
    0x2, 0xd, 0x3, 0x2, 0x2, 0x2, 0x2, 0xf, 0x3, 0x2, 0x2, 0x2, 0x2, 0x11, 
    0x3, 0x2, 0x2, 0x2, 0x2, 0x13, 0x3, 0x2, 0x2, 0x2, 0x2, 0x15, 0x3, 0x2, 
    0x2, 0x2, 0x2, 0x17, 0x3, 0x2, 0x2, 0x2, 0x2, 0x19, 0x3, 0x2, 0x2, 0x2, 
    0x2, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x2, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x2, 0x1f, 
    0x3, 0x2, 0x2, 0x2, 0x2, 0x21, 0x3, 0x2, 0x2, 0x2, 0x2, 0x23, 0x3, 0x2, 
    0x2, 0x2, 0x2, 0x25, 0x3, 0x2, 0x2, 0x2, 0x2, 0x27, 0x3, 0x2, 0x2, 0x2, 
    0x2, 0x29, 0x3, 0x2, 0x2, 0x2, 0x2, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2, 0x2d, 
    0x3, 0x2, 0x2, 0x2, 0x2, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x2, 0x31, 0x3, 0x2, 
    0x2, 0x2, 0x2, 0x33, 0x3, 0x2, 0x2, 0x2, 0x2, 0x35, 0x3, 0x2, 0x2, 0x2, 
    0x2, 0x37, 0x3, 0x2, 0x2, 0x2, 0x2, 0x39, 0x3, 0x2, 0x2, 0x2, 0x2, 0x3b, 
    0x3, 0x2, 0x2, 0x2, 0x2, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x2, 0x3f, 0x3, 0x2, 
    0x2, 0x2, 0x2, 0x41, 0x3, 0x2, 0x2, 0x2, 0x2, 0x43, 0x3, 0x2, 0x2, 0x2, 
    0x2, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x2, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x3, 0x51, 
    0x3, 0x2, 0x2, 0x2, 0x5, 0x53, 0x3, 0x2, 0x2, 0x2, 0x7, 0x55, 0x3, 0x2, 
    0x2, 0x2, 0x9, 0x59, 0x3, 0x2, 0x2, 0x2, 0xb, 0x5c, 0x3, 0x2, 0x2, 0x2, 
    0xd, 0x60, 0x3, 0x2, 0x2, 0x2, 0xf, 0x62, 0x3, 0x2, 0x2, 0x2, 0x11, 
    0x64, 0x3, 0x2, 0x2, 0x2, 0x13, 0x67, 0x3, 0x2, 0x2, 0x2, 0x15, 0x69, 
    0x3, 0x2, 0x2, 0x2, 0x17, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x19, 0x6e, 0x3, 
    0x2, 0x2, 0x2, 0x1b, 0x70, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x72, 0x3, 0x2, 
    0x2, 0x2, 0x1f, 0x74, 0x3, 0x2, 0x2, 0x2, 0x21, 0x76, 0x3, 0x2, 0x2, 
    0x2, 0x23, 0x78, 0x3, 0x2, 0x2, 0x2, 0x25, 0x7e, 0x3, 0x2, 0x2, 0x2, 
    0x27, 0x83, 0x3, 0x2, 0x2, 0x2, 0x29, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x2b, 
    0x92, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x99, 0x3, 0x2, 0x2, 0x2, 0x2f, 0xa5, 
    0x3, 0x2, 0x2, 0x2, 0x31, 0xac, 0x3, 0x2, 0x2, 0x2, 0x33, 0xb0, 0x3, 
    0x2, 0x2, 0x2, 0x35, 0xb6, 0x3, 0x2, 0x2, 0x2, 0x37, 0xbe, 0x3, 0x2, 
    0x2, 0x2, 0x39, 0xc2, 0x3, 0x2, 0x2, 0x2, 0x3b, 0xc9, 0x3, 0x2, 0x2, 
    0x2, 0x3d, 0xd5, 0x3, 0x2, 0x2, 0x2, 0x3f, 0xd8, 0x3, 0x2, 0x2, 0x2, 
    0x41, 0xdc, 0x3, 0x2, 0x2, 0x2, 0x43, 0xe4, 0x3, 0x2, 0x2, 0x2, 0x45, 
    0xee, 0x3, 0x2, 0x2, 0x2, 0x47, 0xf0, 0x3, 0x2, 0x2, 0x2, 0x49, 0xf3, 
    0x3, 0x2, 0x2, 0x2, 0x4b, 0xf5, 0x3, 0x2, 0x2, 0x2, 0x4d, 0xfa, 0x3, 
    0x2, 0x2, 0x2, 0x4f, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0x7, 0x2a, 
    0x2, 0x2, 0x52, 0x4, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x7, 0x2b, 0x2, 
    0x2, 0x54, 0x6, 0x3, 0x2, 0x2, 0x2, 0x55, 0x56, 0x7, 0x63, 0x2, 0x2, 
    0x56, 0x57, 0x7, 0x70, 0x2, 0x2, 0x57, 0x58, 0x7, 0x66, 0x2, 0x2, 0x58, 
    0x8, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 0x7, 0x71, 0x2, 0x2, 0x5a, 0x5b, 
    0x7, 0x74, 0x2, 0x2, 0x5b, 0xa, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5d, 0x7, 
    0x70, 0x2, 0x2, 0x5d, 0x5e, 0x7, 0x71, 0x2, 0x2, 0x5e, 0x5f, 0x7, 0x76, 
    0x2, 0x2, 0x5f, 0xc, 0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 0x7, 0x3f, 0x2, 
    0x2, 0x61, 0xe, 0x3, 0x2, 0x2, 0x2, 0x62, 0x63, 0x7, 0x3e, 0x2, 0x2, 
    0x63, 0x10, 0x3, 0x2, 0x2, 0x2, 0x64, 0x65, 0x7, 0x3e, 0x2, 0x2, 0x65, 
    0x66, 0x7, 0x3f, 0x2, 0x2, 0x66, 0x12, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 
    0x7, 0x40, 0x2, 0x2, 0x68, 0x14, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x7, 
    0x40, 0x2, 0x2, 0x6a, 0x6b, 0x7, 0x3f, 0x2, 0x2, 0x6b, 0x16, 0x3, 0x2, 
    0x2, 0x2, 0x6c, 0x6d, 0x7, 0x2d, 0x2, 0x2, 0x6d, 0x18, 0x3, 0x2, 0x2, 
    0x2, 0x6e, 0x6f, 0x7, 0x2f, 0x2, 0x2, 0x6f, 0x1a, 0x3, 0x2, 0x2, 0x2, 
    0x70, 0x71, 0x7, 0x31, 0x2, 0x2, 0x71, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x72, 
    0x73, 0x7, 0x2c, 0x2, 0x2, 0x73, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 
    0x7, 0x7e, 0x2, 0x2, 0x75, 0x20, 0x3, 0x2, 0x2, 0x2, 0x76, 0x77, 0x7, 
    0x24, 0x2, 0x2, 0x77, 0x22, 0x3, 0x2, 0x2, 0x2, 0x78, 0x79, 0x7, 0x68, 
    0x2, 0x2, 0x79, 0x7a, 0x7, 0x63, 0x2, 0x2, 0x7a, 0x7b, 0x7, 0x6e, 0x2, 
    0x2, 0x7b, 0x7c, 0x7, 0x75, 0x2, 0x2, 0x7c, 0x7d, 0x7, 0x67, 0x2, 0x2, 
    0x7d, 0x24, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7f, 0x7, 0x76, 0x2, 0x2, 0x7f, 
    0x80, 0x7, 0x74, 0x2, 0x2, 0x80, 0x81, 0x7, 0x77, 0x2, 0x2, 0x81, 0x82, 
    0x7, 0x67, 0x2, 0x2, 0x82, 0x26, 0x3, 0x2, 0x2, 0x2, 0x83, 0x84, 0x7, 
    0x44, 0x2, 0x2, 0x84, 0x85, 0x7, 0x4b, 0x2, 0x2, 0x85, 0x86, 0x7, 0x50, 
    0x2, 0x2, 0x86, 0x87, 0x7, 0x43, 0x2, 0x2, 0x87, 0x88, 0x7, 0x54, 0x2, 
    0x2, 0x88, 0x89, 0x7, 0x5b, 0x2, 0x2, 0x89, 0x28, 0x3, 0x2, 0x2, 0x2, 
    0x8a, 0x8b, 0x7, 0x46, 0x2, 0x2, 0x8b, 0x8c, 0x7, 0x47, 0x2, 0x2, 0x8c, 
    0x8d, 0x7, 0x45, 0x2, 0x2, 0x8d, 0x8e, 0x7, 0x4b, 0x2, 0x2, 0x8e, 0x8f, 
    0x7, 0x4f, 0x2, 0x2, 0x8f, 0x90, 0x7, 0x43, 0x2, 0x2, 0x90, 0x91, 0x7, 
    0x4e, 0x2, 0x2, 0x91, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 0x7, 0x67, 
    0x2, 0x2, 0x93, 0x94, 0x7, 0x7a, 0x2, 0x2, 0x94, 0x95, 0x7, 0x6b, 0x2, 
    0x2, 0x95, 0x96, 0x7, 0x75, 0x2, 0x2, 0x96, 0x97, 0x7, 0x76, 0x2, 0x2, 
    0x97, 0x98, 0x7, 0x75, 0x2, 0x2, 0x98, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x99, 
    0x9a, 0x7, 0x4a, 0x2, 0x2, 0x9a, 0x9b, 0x7, 0x47, 0x2, 0x2, 0x9b, 0x9c, 
    0x7, 0x5a, 0x2, 0x2, 0x9c, 0x9d, 0x7, 0x43, 0x2, 0x2, 0x9d, 0x9e, 0x7, 
    0x46, 0x2, 0x2, 0x9e, 0x9f, 0x7, 0x47, 0x2, 0x2, 0x9f, 0xa0, 0x7, 0x45, 
    0x2, 0x2, 0xa0, 0xa1, 0x7, 0x4b, 0x2, 0x2, 0xa1, 0xa2, 0x7, 0x4f, 0x2, 
    0x2, 0xa2, 0xa3, 0x7, 0x43, 0x2, 0x2, 0xa3, 0xa4, 0x7, 0x4e, 0x2, 0x2, 
    0xa4, 0x2e, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa6, 0x7, 0x68, 0x2, 0x2, 0xa6, 
    0xa7, 0x7, 0x71, 0x2, 0x2, 0xa7, 0xa8, 0x7, 0x74, 0x2, 0x2, 0xa8, 0xa9, 
    0x7, 0x63, 0x2, 0x2, 0xa9, 0xaa, 0x7, 0x6e, 0x2, 0x2, 0xaa, 0xab, 0x7, 
    0x6e, 0x2, 0x2, 0xab, 0x30, 0x3, 0x2, 0x2, 0x2, 0xac, 0xad, 0x7, 0x6e, 
    0x2, 0x2, 0xad, 0xae, 0x7, 0x67, 0x2, 0x2, 0xae, 0xaf, 0x7, 0x76, 0x2, 
    0x2, 0xaf, 0x32, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb1, 0x7, 0x6f, 0x2, 0x2, 
    0xb1, 0xb2, 0x7, 0x63, 0x2, 0x2, 0xb2, 0xb3, 0x7, 0x76, 0x2, 0x2, 0xb3, 
    0xb4, 0x7, 0x65, 0x2, 0x2, 0xb4, 0xb5, 0x7, 0x6a, 0x2, 0x2, 0xb5, 0x34, 
    0x3, 0x2, 0x2, 0x2, 0xb6, 0xb7, 0x7, 0x50, 0x2, 0x2, 0xb7, 0xb8, 0x7, 
    0x57, 0x2, 0x2, 0xb8, 0xb9, 0x7, 0x4f, 0x2, 0x2, 0xb9, 0xba, 0x7, 0x47, 
    0x2, 0x2, 0xba, 0xbb, 0x7, 0x54, 0x2, 0x2, 0xbb, 0xbc, 0x7, 0x43, 0x2, 
    0x2, 0xbc, 0xbd, 0x7, 0x4e, 0x2, 0x2, 0xbd, 0x36, 0x3, 0x2, 0x2, 0x2, 
    0xbe, 0xbf, 0x7, 0x72, 0x2, 0x2, 0xbf, 0xc0, 0x7, 0x63, 0x2, 0x2, 0xc0, 
    0xc1, 0x7, 0x74, 0x2, 0x2, 0xc1, 0x38, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 
    0x7, 0x75, 0x2, 0x2, 0xc3, 0xc4, 0x7, 0x76, 0x2, 0x2, 0xc4, 0xc5, 0x7, 
    0x74, 0x2, 0x2, 0xc5, 0xc6, 0x7, 0x6b, 0x2, 0x2, 0xc6, 0xc7, 0x7, 0x70, 
    0x2, 0x2, 0xc7, 0xc8, 0x7, 0x69, 0x2, 0x2, 0xc8, 0x3a, 0x3, 0x2, 0x2, 
    0x2, 0xc9, 0xca, 0x7, 0x6b, 0x2, 0x2, 0xca, 0xcb, 0x7, 0x76, 0x2, 0x2, 
    0xcb, 0xcc, 0x7, 0x67, 0x2, 0x2, 0xcc, 0x3c, 0x3, 0x2, 0x2, 0x2, 0xcd, 
    0xd6, 0x7, 0x32, 0x2, 0x2, 0xce, 0xd2, 0x9, 0x2, 0x2, 0x2, 0xcf, 0xd1, 
    0x5, 0x47, 0x24, 0x2, 0xd0, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd4, 0x3, 
    0x2, 0x2, 0x2, 0xd2, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd3, 0x3, 0x2, 
    0x2, 0x2, 0xd3, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd2, 0x3, 0x2, 0x2, 
    0x2, 0xd5, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xce, 0x3, 0x2, 0x2, 0x2, 
    0xd6, 0x3e, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd9, 0x5, 0x4b, 0x26, 0x2, 0xd8, 
    0xd7, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xda, 0x3, 0x2, 0x2, 0x2, 0xda, 0xd8, 
    0x3, 0x2, 0x2, 0x2, 0xda, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xdb, 0x40, 0x3, 
    0x2, 0x2, 0x2, 0xdc, 0xdd, 0x7, 0x25, 0x2, 0x2, 0xdd, 0xde, 0x7, 0x7a, 
    0x2, 0x2, 0xde, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xe0, 0x5, 0x45, 0x23, 
    0x2, 0xe0, 0xe1, 0x5, 0x45, 0x23, 0x2, 0xe1, 0xe2, 0x5, 0x45, 0x23, 
    0x2, 0xe2, 0xe3, 0x5, 0x45, 0x23, 0x2, 0xe3, 0x42, 0x3, 0x2, 0x2, 0x2, 
    0xe4, 0xe5, 0x5, 0x3d, 0x1f, 0x2, 0xe5, 0xe9, 0x7, 0x30, 0x2, 0x2, 0xe6, 
    0xe8, 0x7, 0x32, 0x2, 0x2, 0xe7, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xeb, 
    0x3, 0x2, 0x2, 0x2, 0xe9, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xea, 0x3, 
    0x2, 0x2, 0x2, 0xea, 0xec, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xe9, 0x3, 0x2, 
    0x2, 0x2, 0xec, 0xed, 0x5, 0x3d, 0x1f, 0x2, 0xed, 0x44, 0x3, 0x2, 0x2, 
    0x2, 0xee, 0xef, 0x9, 0x3, 0x2, 0x2, 0xef, 0x46, 0x3, 0x2, 0x2, 0x2, 
    0xf0, 0xf1, 0x9, 0x4, 0x2, 0x2, 0xf1, 0x48, 0x3, 0x2, 0x2, 0x2, 0xf2, 
    0xf4, 0x9, 0x5, 0x2, 0x2, 0xf3, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf4, 0x4a, 
    0x3, 0x2, 0x2, 0x2, 0xf5, 0xf6, 0x9, 0x6, 0x2, 0x2, 0xf6, 0x4c, 0x3, 
    0x2, 0x2, 0x2, 0xf7, 0xfb, 0x5, 0x47, 0x24, 0x2, 0xf8, 0xfb, 0x5, 0x49, 
    0x25, 0x2, 0xf9, 0xfb, 0x7, 0x30, 0x2, 0x2, 0xfa, 0xf7, 0x3, 0x2, 0x2, 
    0x2, 0xfa, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xf9, 0x3, 0x2, 0x2, 0x2, 
    0xfb, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xfc, 
    0xfd, 0x3, 0x2, 0x2, 0x2, 0xfd, 0x4e, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xff, 
    0x9, 0x7, 0x2, 0x2, 0xff, 0x100, 0x3, 0x2, 0x2, 0x2, 0x100, 0x101, 0x8, 
    0x28, 0x2, 0x2, 0x101, 0x50, 0x3, 0x2, 0x2, 0x2, 0xa, 0x2, 0xd2, 0xd5, 
    0xda, 0xe9, 0xf3, 0xfa, 0xfc, 0x3, 0x2, 0x3, 0x2, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

SimpleSMTLIBLexer::Initializer SimpleSMTLIBLexer::_init;
