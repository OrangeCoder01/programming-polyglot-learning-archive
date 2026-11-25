library ieee;
use ieee.std_logic_1164.all;

entity en_4bit_AND_gate is
    port
    (
        x1, x2: in std_logic_vector(3 downto 0);
        y: out std_logic_vector(3 downto 0)
    );
end entity en_4bit_AND_gate;

architecture ar_4bit_AND_gate of en_4bit_AND_gate is
    begin
        y <= x1 and x2;
end architecture ar_4bit_AND_gate;
