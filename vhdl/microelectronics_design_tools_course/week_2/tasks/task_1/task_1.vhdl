library ieee;
use ieee.std_logic_1164.all;

--- AND Gate Part
entity en_and_gate is
    port
    (
        x1, x2: in std_logic;
        z: out std_logic
    );
end entity en_and_gate;

architecture ar_and_gate of en_and_gate is
    begin
        z <= x1 and x2;
end architecture ar_and_gate;
