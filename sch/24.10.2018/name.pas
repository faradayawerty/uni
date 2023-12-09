var s : string;
var word1, word2, word3 : string;

begin
	readln(s);

	word1 := copy(s, 1, pos(' ', s));
	delete(s, 1, pos(' ', s));

	word2 := copy(s, 1, pos(' ', s));
	delete(s, 1, pos(' ', s));
	
	word3 := s;

	writeln(word2 + word1[1] + '.' + word3[1] + '.');
end.


