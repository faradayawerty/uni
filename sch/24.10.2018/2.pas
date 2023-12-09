var s : string;
var i, c : integer;

begin
	readln(s);
	
	c := 0;

	for i := 1 to length(s) do 
		if s[i] = 'a' then
		begin
			s[i] := 'b';
			c += 1;
		end;
	
	writeln(c);
	writeln(s);
end.


