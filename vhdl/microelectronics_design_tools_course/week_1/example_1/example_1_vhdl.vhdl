library ieee;
use ieee.std_logic_1164.all;

entity nand_gate is
    port 
    (
        a, b: in std_logic;
        z: out std_logic
    );
end entity nand_gate;

architecture model of nand_gate is
    begin
        z <= a nand b;
end architecture model;