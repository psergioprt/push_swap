define display_args
	set $i = 1
	while $i < argc
		printf "argv[%d] = %s\n", $i, argv[$i]
		set $i = $i + 1
	end
end
