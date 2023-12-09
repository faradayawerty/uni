var f : text;
var c : char;

begin
	assign(f, 'file3.txt');
	reset(f);

	while not eof(f) do {eof = end of file}
	begin 
		read(f, c);
		write(c);
	end;

	close(f);
end.
