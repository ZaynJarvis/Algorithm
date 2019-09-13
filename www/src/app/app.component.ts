import { Component } from '@angular/core';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.scss'],
})
export class AppComponent {
  title = 'algorithm';
  create = false;
  onClick() {
    this.create = true;
  }
  close() {
    this.create = false;
  }
}
