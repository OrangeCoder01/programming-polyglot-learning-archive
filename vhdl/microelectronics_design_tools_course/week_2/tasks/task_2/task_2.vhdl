library ieee;
use ieee.std_logic_1164.all;

--- OR Gate Part
entity en_or_gate is
    port
    (
        x1, x2: in std_logic;
        z: out std_logic
    );
end entity en_or_gate;

architecture ar_or_gate of en_or_gate is
    begin
        z <= x1 or x2;
end architecture ar_or_gate;


library ieee;
use ieee.std_logic_1164.all;

--- XOR Gate Part
entity en_xor_gate is
    port
    (
        x3, x4: in std_logic;
        y: out std_logic
    );
end entity en_xor_gate;

architecture ar_xor_gate of en_xor_gate is
    begin
        y <= x3 xor x4;
        
end architecture ar_xor_gate;