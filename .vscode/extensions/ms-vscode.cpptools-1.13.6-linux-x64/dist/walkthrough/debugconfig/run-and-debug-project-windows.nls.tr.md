<h1 data-loc-id="walkthrough.windows.title.run.and.debug.your.file">Windows üzerinde C++ dosyanızı çalıştırma ve hatalarını ayıklama</h1>
<p data-loc-id="walkthrough.windows.run.and.debug.your.file">C++ dosyanızı VS Code'da çalıştırıp hatalarını ayıklamak için:</p>
<ol>
<li><p data-loc-id="walkthrough.windows.instructions1">Çalıştırıp hatalarını ayıklamak istediğiniz C++ kaynak dosyasını açın. Bu dosyanın düzenleyicide etkin (görünüp seçildiğinden) olduğundan emin olun.</p>
</li>
<li><p data-loc-id="walkthrough.windows.press.f5"><code>F5</code> tuşuna basın. Alternatif olarak, ana menüden <strong><span data-loc-id="walkthrough.windows.run" data-loc-hint="Refers to Run command on main menu">Çalıştır</span> &gt; <span data-loc-id="walkthrough.windows.start.debugging" data-loc-hint="Refers to Start Debugging command under Run menu on main menu">Hata Ayıklamayı Başlat</span></strong> seçeneğini belirleyin.</p>
</li>
<li><p data-loc-id="walkthrough.windows.select.compiler"><strong>C++ (Windows)</strong> seçin.</p>
</li>
<li><p data-loc-id="walkthrough.windows.choose.build.active.file"><strong>cl.exe - <span data-loc-id="walkthrough.windows.build.and.debug.active.file" data-loc-hint="Should be the same as translation for build.and.debug.active.file in extension.ts">Etkin dosyayı derle ve dosyada hata ayıkla</span></strong> seçin.</p>
</li>
</ol>
<p data-loc-id="walkthrough.windows.after.running">C++ dosyanızı ilk kez çalıştırıp hatalarını ayıkladıktan sonra projenizin <strong>.vscode</strong> klasöründe iki yeni dosya olduğunu fark edeceksiniz: <strong>tasks.json</strong> ve <strong>launch.json</strong>.</p>

<p data-loc-id="walkthrough.windows.for.more.complex">Daha karmaşık derleme ve hata ayıklama senaryoları için <span>tasks.json</span> ve <span>launch.json</span> içindeki derleme görevlerinizi özelleştirebilir ve yapılandırmalarınızın hatalarını ayıklayabilirsiniz. Örneğin, komut satırından derleme yaparken bağımsız değişkenleri derleyicinize geçirirseniz <strong>compilerArgs</strong> özelliğini kullanarak bu bağımsız değişkenleri <span>tasks.json</span> içinde belirtebilirsiniz. Benzer şekilde, <span>launch.json</span> içinde hata ayıklama için programınıza geçirilecek bağımsız değişkenleri tanımlayabilirsiniz.</p>
