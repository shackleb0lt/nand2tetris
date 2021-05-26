
import sys

# String constants:
TOKEN_TYPES = ["KEYWORD", "SYMBOL", "IDENTIFIER", "INT_CONST", "STRING_CONST"]

TOKEN_KEYWORDS = ["CLASS", "METHOD", "FUNCTION", "CONSTRUCTOR", "INT",\
					"BOOLEAN", "CHAR", "VOID", "VAR", "STATIC", "FIELD", \
					"LET", "DO", "IF", "ELSE", "WHILE", "RETURN", "TRUE", \
					"FALSE", "NULL", "THIS"]

SYMBOLS = ['(', ')', '[', ']', '{', '}', ',', ';', '=', '.', '+', '-', '*', \
		 '/', '&', '|', '~', '<', '>']

WHITE_SPACE = [' ', '\n', '\t']


class JackTokenizer:
	_tokenTypes         = frozenset(TOKEN_TYPES)
	_keywords           = frozenset(TOKEN_KEYWORDS)
	_symbols            = frozenset(SYMBOLS)
	_whiteSpace         = frozenset(WHITE_SPACE)

	def __init__(self, filename):
		self.file = open(filename, 'r')
		self.currentToken = ""
		if self.hasMoreTokens():
			self.advance()

	def __del__(self):
		self.file.close()

	def hasMoreTokens(self):
		while True:
			if self._peek() == "":
				return False

			# Skipping spaces and newlines:
			while self._peek() in self._whiteSpace:
				self._pop()
			# Skipping comments:
			st = self._peek(2)
			while st in ["//", "/*"]:
				if self._peek(2) == "//":
					self._skipLine()
				else:
					self._skipComment()

				st = self._peek(2)

			if self._peek() not in self._whiteSpace:
				return True

	def advance(self):
		if self.hasMoreTokens():
			if self._peek() != '"':
				self.currentToken = self._peekWord()
				self._pop(len(self.currentToken))
			else:
				string_const = self._pop() 
				while self._peek() != '"':
					string_const = string_const + self._pop()
				string_const = string_const + self._pop() 

				self.currentToken = string_const
			
	def tokenType(self):
		token = self.currentToken.upper()
		if token in self._symbols:
			return "SYMBOL"
		if token in self._keywords:
			return "KEYWORD"
		if '"' in token:
			return "STRING_CONST"
		if token.isdigit():
			return "INT_CONST"

		return "IDENTIFIER"

	def keyWord(self):
		return self.currentToken.upper()

	def symbol(self):
		return self.currentToken[0]

	def identifier(self):
		return self.currentToken

	def intVal(self):
		return int(self.currentToken)

	def stringVal(self):
		return self.currentToken.replace('"', '')

	# -- Private --
	def _rawToken(self):
		return self.currentToken

	def _peek(self, charCount=1):
		
		originalPos = self.file.tell()
		c = self.file.read(charCount)
		self.file.seek(originalPos)
		return c

	def _pop(self, charCount=1):
		return self.file.read(charCount)

	def _skipLine(self):
		self.file.readline()

	def _skipComment(self):
		
		star = False
		while True:
			char = self._pop()
			if char == '*':
				star = True
			else:

				if star == True and char == '/':
					return
				
				if char != '\n':
					star = False

	def _peekWord(self):
		''' Read until finding a whitespace character or a symbol. 
		(Restores the pointer.) '''
		res = ""
		originalPos = self.file.tell()
		currentChar = self._pop()
		if currentChar in self._symbols:
			res = currentChar
		else:
			while (currentChar != "") and (currentChar not in self._whiteSpace):
				if currentChar in self._symbols:
					break
				res = res + currentChar
				currentChar = self._pop()
		self.file.seek(originalPos)
		return res

def main():
	if len(sys.argv) < 2:
		print("Error. Missing argument [filename]")
		return -1

	filename = sys.argv[1]
	filenameXML=""
	for s in sys.argv[1]:
                        if s==".":
                                break
                        filenameXML +=s
                  
	jt = JackTokenizer(filename)
	filenameXML+=".tok"
	fileXML=open(filenameXML,"w")
	while jt.hasMoreTokens():
		print(jt._rawToken(), jt.tokenType(), sep='\t')
		fileXML.write("<"+jt.tokenType().lower()+"> "+jt._rawToken()+" </"+jt.tokenType().lower()+">\n")
		jt.advance()

	print(jt._rawToken(), jt.tokenType(), sep='\t') 

if __name__ == '__main__':
	main()
