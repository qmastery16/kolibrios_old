if tup.getconfig("NO_FASM") ~= "" then return end
tup.rule("Fever_blue.asm", 'fasm "%f" "%o" ' .. tup.getconfig("KPACK_CMD"), "Fever2 blue.skn")
