library ieee;
use ieee.std_logic_1164.all;

entity en_mux4to1 is
    port (
        d    : in  std_logic_vector(3 downto 0);
        sel  : in  std_logic_vector(1 downto 0);
        en_n : in  std_logic;
        y    : out std_logic
    );
end entity en_mux4to1;

architecture ar_mux4to1 of en_mux4to1 is
begin
    y <= '0'  when en_n = '1' else
         d(0) when sel = "00" else
         d(1) when sel = "01" else
         d(2) when sel = "10" else
         d(3);
end architecture ar_mux4to1;