var s : string;

begin
	readln(s);

	writeln(copy(s, 1, length(s) div 2 + length(s) mod 2));
	writeln(copy(s, length(s) div 2 + 1, length(s) div 2 + length(s) mod 2));
end.


