//===- ARMFixupKinds.h ----------------------------------------------------===//
//
//                     The MCLinker Project
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#ifndef MCLD_LIB_TARGET_ARM_ARM_FIXUP_KINDS_H_
#define MCLD_LIB_TARGET_ARM_ARM_FIXUP_KINDS_H_

#include <llvm/MC/MCFixup.h>

namespace mcld {
namespace ARM {

enum Fixups {
  // fixup_arm_ldst_pcrel_12 - 12-bit PC relative relocation for symbol
  // addresses
  fixup_arm_ldst_pcrel_12 = FirstTargetFixupKind,

  // fixup_t2_ldst_pcrel_12 - Equivalent to fixup_arm_ldst_pcrel_12, with
  // the 16-bit halfwords reordered.
  fixup_t2_ldst_pcrel_12,

  // fixup_arm_pcrel_10 - 10-bit PC relative relocation for symbol addresses
  // used in VFP instructions where the lower 2 bits are not encoded
  // (so it's encoded as an 8-bit immediate).
  fixup_arm_pcrel_10,
  // fixup_t2_pcrel_10 - Equivalent to fixup_arm_pcrel_10, accounting for
  // the short-swapped encoding of Thumb2 instructions.
  fixup_t2_pcrel_10,
  // fixup_thumb_adr_pcrel_10 - 10-bit PC relative relocation for symbol
  // addresses where the lower 2 bits are not encoded (so it's encoded as an
  // 8-bit immediate).
  fixup_thumb_adr_pcrel_10,
  // fixup_arm_adr_pcrel_12 - 12-bit PC relative relocation for the ADR
  // instruction.
  fixup_arm_adr_pcrel_12,
  // fixup_t2_adr_pcrel_12 - 12-bit PC relative relocation for the ADR
  // instruction.
  fixup_t2_adr_pcrel_12,
  // fixup_arm_condbranch - 24-bit PC relative relocation for conditional branch
  // instructions. 
  fixup_arm_condbranch,
  // fixup_arm_uncondbranch - 24-bit PC relative relocation for 
  // branch instructions. (unconditional)
  fixup_arm_uncondbranch,
  // fixup_t2_condbranch - 20-bit PC relative relocation for Thumb2 direct
  // unconditional branch instructions.
  fixup_t2_condbranch,
  // fixup_t2_uncondbranch - 20-bit PC relative relocation for Thumb2 direct
  // branch unconditional branch instructions.
  fixup_t2_uncondbranch,

  // fixup_arm_thumb_br - 12-bit fixup for Thumb B instructions.
  fixup_arm_thumb_br,

  // fixup_arm_thumb_bl - Fixup for Thumb BL instructions.
  fixup_arm_thumb_bl,

  // fixup_arm_thumb_blx - Fixup for Thumb BLX instructions.
  fixup_arm_thumb_blx,

  // fixup_arm_thumb_cb - Fixup for Thumb branch instructions.
  fixup_arm_thumb_cb,

  // fixup_arm_thumb_cp - Fixup for Thumb load/store from constant pool instrs.
  fixup_arm_thumb_cp,

  // fixup_arm_thumb_bcc - Fixup for Thumb conditional branching instructions.
  fixup_arm_thumb_bcc,

  // The next two are for the movt/movw pair
  // the 16bit imm field are split into imm{15-12} and imm{11-0}
  fixup_arm_movt_hi16, // :upper16:
  fixup_arm_movw_lo16, // :lower16:
  fixup_t2_movt_hi16, // :upper16:
  fixup_t2_movw_lo16, // :lower16:

  // It is possible to create an "immediate" that happens to be pcrel.
  // movw r0, :lower16:Foo-(Bar+8) and movt  r0, :upper16:Foo-(Bar+8)
  // result in different reloc tags than the above two.
  // Needed to support ELF::R_ARM_MOVT_PREL and ELF::R_ARM_MOVW_PREL_NC
  fixup_arm_movt_hi16_pcrel, // :upper16:
  fixup_arm_movw_lo16_pcrel, // :lower16:
  fixup_t2_movt_hi16_pcrel, // :upper16:
  fixup_t2_movw_lo16_pcrel, // :lower16:

  // Marker
  LastTargetFixupKind,
  NumTargetFixupKinds = LastTargetFixupKind - FirstTargetFixupKind
};

} // namespace ARM
} // namespace mcld

#endif
