prefix_source TEST_edg_x86_64 build/gcc/environment.sh
prefix_source TEST_edg_x86_64 wrapper4.sh
exec edgy --config="edg_x86_64" --run-timestamp="2026.10.06-00.04.25" --max-failure-count=10 --timeout=600 -A -D --meticulous ilazaric/test1.sft.cpp
