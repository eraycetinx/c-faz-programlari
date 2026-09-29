# Faz 1 (faz1-dsa) - genel Makefile
#
# Kural: her modul icin
#   include/<ad>.h   spesifikasyon (API)
#   src/<ad>.c       senin implementasyonun
#   tests/test_<ad>.c testler
# Yeni bir modul eklemek icin bu dosyayi degistirmen gerekmez: yeni
# test dosyasi eklediginde make onu otomatik bulur.
#
# Komutlar:
#   make check-<ad>     normal test + ASan/UBSan + valgrind (ornek: make check-stack)
#   make test-<ad>      sadece normal test
#   make asan-<ad>      sadece ASan/UBSan
#   make valgrind-<ad>  sadece valgrind
#   make bench-<ad>     bench/bench_<ad>.c dosyasini -O2 ile derleyip calistirir
#   make check          src/ altinda kaynagi olan TUM modulleri kontrol eder
#   make drills         arac tatbikati programlari (bilerek hatali)
#   make clean
#
# Bir modul baska bir modulun kodunu kullaniyorsa bagimliligi asagiya yaz.
# Ilgili kaynak dosyayi YAZDIKTAN SONRA satirin basindaki # isaretini kaldir
# (dosya yokken yorumu kaldirirsan make "No rule to make target" der).
# DEPS_queue      := src/stack.c                  # M5 Gun 3
# DEPS_expr       := src/stack.c                  # M5 Gun 1
# DEPS_avl        := src/bst.c                    # M7 Gun 2 (benchmark icin)
# DEPS_hashmap_oa := src/hashmap.c                # M10 Gun 3 (benchmark icin)
# DEPS_graph      := src/queue.c src/stack.c      # M11 Gun 1
# DEPS_graph      := src/queue.c src/stack.c src/pq.c              # M11 Gun 2
# DEPS_graph      := src/queue.c src/stack.c src/pq.c src/dsu.c    # M11 Gun 3
# (graph icin her gun bir oncekinin yerine yenisini kullan)

CC        ?= gcc
CSTD      := -std=c11 -D_POSIX_C_SOURCE=200809L
WARN      := -Wall -Wextra -Wpedantic -Wshadow -Werror
CFLAGS    := $(CSTD) $(WARN) -g -O0 -Iinclude
BENCHFLAGS:= $(CSTD) $(WARN) -O2 -Iinclude
ASANFLAGS := -fsanitize=address,undefined -fno-omit-frame-pointer
VALGRIND  := valgrind -q --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all --error-exitcode=1

BIN  := build
ABIN := build-asan

ALL_MODS := $(patsubst tests/test_%.c,%,$(wildcard tests/test_*.c))
READY    := $(filter $(ALL_MODS),$(patsubst src/%.c,%,$(wildcard src/*.c)))
BENCHES  := $(patsubst bench/bench_%.c,%,$(wildcard bench/bench_*.c))
DRILLS   := $(patsubst drills/%.c,%,$(wildcard drills/*.c))
HEADERS  := $(wildcard include/*.h) tests/test.h

TEST_T  := $(addprefix test-,$(ALL_MODS))
ASAN_T  := $(addprefix asan-,$(ALL_MODS))
VG_T    := $(addprefix valgrind-,$(ALL_MODS))
CHECK_T := $(addprefix check-,$(ALL_MODS))
BENCH_T := $(addprefix bench-,$(BENCHES))

.PHONY: check drills clean $(TEST_T) $(ASAN_T) $(VG_T) $(CHECK_T) $(BENCH_T)

check:
	@for m in $(READY); do $(MAKE) --no-print-directory check-$$m || exit 1; done
	@echo "== HAZIR MODULLERIN TUMU GECTI: $(READY) =="

$(BIN) $(ABIN):
	mkdir -p $@

.SECONDEXPANSION:

$(BIN)/test_%: tests/test_%.c src/%.c $$(DEPS_$$*) $(HEADERS) | $(BIN)
	$(CC) $(CFLAGS) $< src/$*.c $(DEPS_$*) -o $@

$(ABIN)/test_%: tests/test_%.c src/%.c $$(DEPS_$$*) $(HEADERS) | $(ABIN)
	$(CC) $(CFLAGS) $(ASANFLAGS) $< src/$*.c $(DEPS_$*) -o $@

$(BIN)/bench_%: bench/bench_%.c src/%.c $$(DEPS_$$*) $(HEADERS) | $(BIN)
	$(CC) $(BENCHFLAGS) $< src/$*.c $(DEPS_$*) -o $@

$(BIN)/drill_%: drills/%.c | $(BIN)
	$(CC) $(CSTD) -g -O0 $< -o $@

$(ABIN)/drill_%: drills/%.c | $(ABIN)
	$(CC) $(CSTD) -g -O0 $(ASANFLAGS) $< -o $@

$(TEST_T): test-%: $(BIN)/test_%
	./$<

$(ASAN_T): asan-%: $(ABIN)/test_%
	./$<

$(VG_T): valgrind-%: $(BIN)/test_%
	$(VALGRIND) ./$<

$(CHECK_T): check-%:
	@$(MAKE) --no-print-directory test-$*
	@$(MAKE) --no-print-directory asan-$*
	@$(MAKE) --no-print-directory valgrind-$*
	@echo "== $*: normal + ASan/UBSan + valgrind GECTI =="

$(BENCH_T): bench-%: $(BIN)/bench_%
	./$<

drills: $(addprefix $(BIN)/drill_,$(DRILLS)) $(addprefix $(ABIN)/drill_,$(DRILLS))

clean:
	rm -rf $(BIN) $(ABIN)
