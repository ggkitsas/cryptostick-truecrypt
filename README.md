# TrueCrypt smartcard support (Google Summer of Code project)

True Crypt has the capability to use smart cards (via PKCS#11) to unlock encrypted volumes. However, this feature is suboptimal, from a security standpoint, and needs to be improved. Currently, TrueCrypt simply stores the so-called keyfile in the PIN protected smart card. Instead, TrueCrypt should use the expected challenge-response mechanism of smart cards. The volume key should be encrypted with the smartcard's certificate/key and stored in the volume. In order to unlock an encrypted volume, TrueCrypt should send the encrypted volume key to the smart card and receive the unencrypted key back. The unencrypted key should never be stored. User documentation incl. screenshots should be created.

### Tasks

1. Understand PKCS#11 interface and TrueCrypt's internals
3. Develop a solution and agree with TrueCrypt's developers 
4. Patch and test TrueCrypt with Crypto Stick
5. Commit the patch to TrueCrypt and incorporate potential feedback from developers
6. Publish a fork of TrueCrypt including binaries
7. Create user documentation

### Folder structure
- `truecrypt/`contains
     - TrueCrypt source code
     - wxwidgets sources needed for building TrueCrypt
     - PKCS#11 headers

- `docs/`
   contains documentation
