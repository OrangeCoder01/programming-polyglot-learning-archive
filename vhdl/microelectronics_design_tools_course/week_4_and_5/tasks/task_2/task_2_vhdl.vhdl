library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity en_parity_ok
    port
    (
        d: in std_logic_vector(7 downto 0);
        parity_check: out std_logic
    );
end entity en_parity_ok;

architecture ar_parity_check of en_parity_check is
    begin
        parity_check <= '1' when ((d(0) xor d(1) xor d(2) xor d(3) xor d(4) xor d(5) xor d(6) xor d(7)) = '0') else '0';
end architecture ar_parity_check;