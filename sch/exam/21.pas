var s : string;
var i, c : integer;

begin
	readln(s);
	c := 0;
	for i := 1 to length(s) do
		if s[i] = 'z' then
		begin
			s[i] := 's';
			c += 1;
		end;
	writeln(s);
	writeln(c);
end.
